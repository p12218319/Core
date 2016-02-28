/*
Copyright 2016 Adam Smith - P12218319

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.

email : p12218319@myemail.dmu.ac.uk
*/

#include <windows.h>
#include <map>
#include <mutex>
#include "P12218319\core\DynamicLibrary.hpp"

#if P12218319_OS != P12218319_WINDOWS
	#error P12218319::Core::CompilerGCC : Only implemented for MinGW
#endif

namespace P12218319 {

	#if P12218319_OS == P12218319_WINDOWS
		class P12218319_EXPORT_API DynamicLibraryImplementation : public DynamicLibrary {
		private:
			HMODULE mModule;
		protected:
			// Inherited from DynamicLibrary
			DynamicLibrary::FunctionPtr P12218319_CALL LoadFunction_(const std::string& aPath) const throw() override {
				return mModule ? reinterpret_cast<DynamicLibrary::FunctionPtr>(GetProcAddress(mModule, aPath.c_str())) : nullptr;
			}
		public:
			P12218319_CALL DynamicLibraryImplementation(const std::string& aPath) :
				mModule(::LoadLibraryA(aPath.c_str()))
			{}

			P12218319_CALL ~DynamicLibraryImplementation() {
				if(mModule) FreeLibrary(mModule);
			}

			inline bool P12218319_CALL IsLoaded() const throw() {
				return mModule ? true : false;
			}
		};
	#else
		#error P12218319::Core::DynamicLibrary : Only implemented for Windows
	#endif

	std::mutex LIB_MAP_LOCK;
	std::map<std::string, std::weak_ptr<DynamicLibraryImplementation>> LIB_MAP;

	std::shared_ptr<DynamicLibrary> P12218319_CALL LoadLibrary(const std::string& aPath) throw() {
		std::shared_ptr<DynamicLibraryImplementation> ptr;
		std::lock_guard<std::mutex> lock(LIB_MAP_LOCK);
		auto it = LIB_MAP.find(aPath);
		if(it != LIB_MAP.end()) {
			it = LIB_MAP.emplace(aPath, std::weak_ptr<DynamicLibraryImplementation>()).first;
		}
		ptr = it->second.lock();
		if(! ptr) {
			ptr.reset(new DynamicLibraryImplementation(aPath));
			it->second = ptr;
		}
		return ptr->IsLoaded() ? std::shared_ptr<DynamicLibrary>() : ptr;
	}
}
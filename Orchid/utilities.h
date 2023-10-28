#pragma once

#if OC_DEBUG==2
	#define OC_ERROR(x) std::cout<<x<<std::endl;
	#define OC_LOG(x) std::cout<<x<<std::endl;
#elif OC_DEBUG==1
	#define OC_ERROR(x) std::cout<<x<<std::endl;
	#define OC_LOG(x) 
#else
	#define OC_ERROR(x) 
	#define OC_LOG(x) 
#endif


#ifdef OC_MSCPP
	#ifdef OC_LIB
		#define OC_API __declspec(dllexport)
	#else
		#define OC_API __declspec(dllimport)
	#endif
#else
	#define OC_API
#endif


#define OC_APPLICATION_START(ClassName) \
int main() {\
	ClassName::Init();\
	ClassName::RunInterface();\
	return(0);\
}

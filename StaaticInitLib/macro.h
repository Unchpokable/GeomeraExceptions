#pragma once

//#define STATIC_CONSTRUCTOR(className, priority) \
//    static void className##_StaticInit(); \
//    class className##_Init \
//    { \
//    public: \
//        className##_Init() \
//        { \
//            std::cout << "Macro Debug: Initialization of " << #className << "\n"; \
//            StaticInit::addInitFunction(className##_StaticInit, priority); \
//        }\
//    }; \
//    static className##_Init className##_init;

#define STATIC_CONSTRUCTOR(className, priority) \
    static void StaticInit(); \
    private: \
    inline static StaticInitialization<className> init = StaticInitialization<className>(priority);

#define STATIC_CONSTRUCTOR_IMPL(className) \
    void className##::StaticInit()
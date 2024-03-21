#pragma once

#define STATIC_CONSTRUCTOR(className, priority) \
    static void StaticInit(); \
    private: \
    inline static StaticInitialization<className> init = StaticInitialization<className>(priority);

#define STATIC_CONSTRUCTOR_IMPL(className) \
    void className##::StaticInit()
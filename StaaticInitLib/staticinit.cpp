#include "staticinit.h"

std::shared_ptr<StaticInit> StaticInit::_staticInit;

StaticInit::StaticInit() : _initialized(false)
{
}

void StaticInit::addInitFunction(const InitFunction &function, Priority priority) {
    const auto initializer = createIfNotExists();

    initializer->_initializers.insert(map_value(priority, function));
}

void StaticInit::execute() {
    const auto initializer = createIfNotExists();

    //GEOMERA_LOGIC_ASSERT_MESSAGE(!initializer->_initialized, "static initializers have been runned");

    auto highPriorityFuncs = initializer->_initializers.equal_range(Priority::High);

    for (auto it = highPriorityFuncs.first; it != highPriorityFuncs.second;)
    {
        it->second();
        ++it;
    }

    auto lowPriorityFuncs = initializer->_initializers.equal_range(Priority::Normal);

    for(auto it = lowPriorityFuncs.first; it != lowPriorityFuncs.second;) {
        it->second();
        ++it;
    }

    initializer->_initialized = true;
}

StaticInit* StaticInit::createIfNotExists() {
    if(!instanceIfExists()) {
        _staticInit.reset(new StaticInit);
    }

    return instance();
}

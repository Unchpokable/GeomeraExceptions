#pragma once

#include <functional>
#include <memory>
#include <unordered_map>

#include "singleton.h"

class StaticInit final : public Singleton<StaticInit>
{ // TODO: singleton without params
public:
    using InitFunction = std::function<void()>;

    enum class Priority {
        Normal = 0,
        High = 1
    };

    StaticInit();
    virtual ~StaticInit() = default;

    static void addInitFunction(const InitFunction &function, Priority priority);

    static void execute();

private:
    static StaticInit* createIfNotExists();

    static std::shared_ptr<StaticInit> _staticInit;

    bool _initialized;

    std::unordered_multimap<Priority, InitFunction> _initializers;

    using map_value = std::unordered_multimap<Priority, InitFunction>::value_type;
};

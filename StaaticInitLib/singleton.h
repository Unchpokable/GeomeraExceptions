#pragma once

template<typename T>
class Singleton {
public:
    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;

    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;

protected:
    Singleton() {
        checkInstancePresence(false);

        _instance = static_cast<T*>(this);
    }

    virtual ~Singleton() {
        _instance = nullptr;
    }

    static T* instance() {
        checkInstancePresence();

        return _instance;
    }

    static T* instanceIfExists() {
        return _instance;
    }

private:
    static void checkInstancePresence(bool presence = true) {
        /*GEOMERA_LOGIC_ASSERT_MESSAGE(presence == static_cast<bool>(_instance),
            presence ? "no singleton instance" : "duplicate singleton instance");*/
    }

    static T* _instance;
};

template<typename T>
T* Singleton<T>::_instance = nullptr;

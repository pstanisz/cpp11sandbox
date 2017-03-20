#include "threadsafesingleton.hh"

mutex gInterfaceFun;

ThreadSafeSingleton::ThreadSafeSingleton()
{
    cout << "Singleton private constructor called" << endl;
}

ThreadSafeSingleton &ThreadSafeSingleton::getInstance()
{
    static ThreadSafeSingleton instance;

    return instance;
}

ThreadSafeSingleton::~ThreadSafeSingleton()
{
    cout << "Singleton destructor called" << endl;
}

void ThreadSafeSingleton::interfaceFun()
{
    lock_guard<mutex> lLock(gInterfaceFun);
    cout << "interfaceFun() called from singleton with threadId = " << this_thread::get_id() << endl;
}

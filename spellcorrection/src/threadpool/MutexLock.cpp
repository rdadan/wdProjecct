 ///
 /// @file    MutexLock.cc
 /// @author  rxianjin@163.com
 ///

#include "MutexLock.h"
#include <iostream>

namespace wd
{
MutexLock::MutexLock()
: _isLocking(false)
{
	pthread_mutex_init(&_mutex, NULL);
}

MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}


void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
	_isLocking = true;
}

void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
	_isLocking = false;
}

pthread_mutex_t * MutexLock::getMutexLockPtr()
{
	return &_mutex;
}

}//end of namespace wd

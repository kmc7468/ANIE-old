#include <anie/mutex.hpp>

namespace anie // mutex
{
	void mutex::reader_lock()
	{
		mutex_.lock();
	}
	void mutex::writer_lock()
	{
		mutex_.lock();
	}
	void mutex::reader_unlock()
	{
		mutex_.unlock();
	}
	void mutex::writer_unlock()
	{
		mutex_.unlock();
	}
	bool mutex::reader_try_lock()
	{
		return mutex_.try_lock();
	}
	bool mutex::writer_try_lock()
	{
		return mutex_.try_lock();
	}

	void* mutex::native_handle()
	{
		return mutex_.native_handle();
	}

	mutex_base_ptr make_mutex()
	{
		return std::make_unique<mutex>();
	}
}

namespace anie // shared_mutex
{
	void shared_mutex::reader_lock()
	{
		mutex_.lock_shared();
	}
	void shared_mutex::writer_lock()
	{
		mutex_.lock();
	}
	void shared_mutex::reader_unlock()
	{
		mutex_.unlock_shared();
	}
	void shared_mutex::writer_unlock()
	{
		mutex_.unlock();
	}
	bool shared_mutex::reader_try_lock()
	{
		return mutex_.try_lock_shared();
	}
	bool shared_mutex::writer_try_lock()
	{
		return mutex_.try_lock();
	}

	void* shared_mutex::native_handle()
	{
		return mutex_.native_handle();
	}

	mutex_base_ptr make_shared_mutex()
	{
		return std::make_unique<shared_mutex>();
	}
}

namespace anie // shared_mutex2
{
	void shared_mutex2::reader_lock()
	{
		while (waiting_writer_count_);

		mutex_.lock_shared();
	}
	void shared_mutex2::writer_lock()
	{
		++waiting_writer_count_;
		mutex_.lock();
		--waiting_writer_count_;
	}
	void shared_mutex2::reader_unlock()
	{
		mutex_.unlock_shared();
	}
	void shared_mutex2::writer_unlock()
	{
		mutex_.unlock();
	}
	bool shared_mutex2::reader_try_lock()
	{
		if (waiting_writer_count_) return false;

		return mutex_.try_lock_shared();
	}
	bool shared_mutex2::writer_try_lock()
	{
		return mutex_.try_lock();
	}

	void* shared_mutex2::native_handle()
	{
		return mutex_.native_handle();
	}

	mutex_base_ptr make_shared_mutex2()
	{
		return std::make_unique<shared_mutex2>();
	}
}
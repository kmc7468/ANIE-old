#ifndef ANIE_HEADER_MUTEX_HPP
#define ANIE_HEADER_MUTEX_HPP
#include <anie/config.hpp>

#include <atomic>
#include <cstddef>
#include <memory>
#include <mutex>
#include <shared_mutex>

namespace anie
{
	class ANIE_EXPORT mutex_base
	{
	public:
		mutex_base(const mutex_base& mutex) = delete;
		mutex_base(mutex_base&& mutex) = delete;
		virtual ~mutex_base() = default;

	protected:
		mutex_base() noexcept = default;

	public:
		mutex_base& operator=(const mutex_base& mutex) = delete;
		mutex_base& operator=(mutex_base&& mutex) = delete;
		bool operator==(const mutex_base& mutex) = delete;
		bool operator!=(const mutex_base& mutex) = delete;

	public:
		virtual void reader_lock() noexcept = 0;
		virtual void writer_lock() noexcept = 0;
		virtual void reader_unlock() noexcept = 0;
		virtual void writer_unlock() noexcept = 0;
		virtual bool reader_try_lock() noexcept = 0;
		virtual bool writer_try_lock() noexcept = 0;
		virtual void* native_handle() noexcept = 0;
	};

	using mutex_base_ptr = std::unique_ptr<mutex_base>;

	class ANIE_EXPORT mutex final : public mutex_base
	{
	public:
		mutex() = default;
		mutex(const mutex& mutex) = delete;
		mutex(mutex&& mutex) = delete;
		virtual ~mutex() override = default;

	public:
		mutex& operator=(const mutex& mutex) = delete;
		mutex& operator=(mutex&& mutex) = delete;
		bool operator==(const mutex& mutex) = delete;
		bool operator!=(const mutex& mutex) = delete;

	public:
		virtual void reader_lock() noexcept override;
		virtual void writer_lock() noexcept override;
		virtual void reader_unlock() noexcept override;
		virtual void writer_unlock() noexcept override;
		virtual bool reader_try_lock() noexcept override;
		virtual bool writer_try_lock() noexcept override;
		virtual void* native_handle() noexcept override;

	private:
		std::mutex mutex_;
	};

	ANIE_EXPORT mutex_base_ptr make_mutex();

	class ANIE_EXPORT shared_mutex final : public mutex_base
	{
	public:
		shared_mutex() = default;
		shared_mutex(const shared_mutex& mutex) = delete;
		shared_mutex(shared_mutex&& mutex) = delete;
		virtual ~shared_mutex() override = default;

	public:
		shared_mutex& operator=(const shared_mutex& mutex) = delete;
		shared_mutex& operator=(shared_mutex&& mutex) = delete;
		bool operator==(const shared_mutex& mutex) = delete;
		bool operator!=(const shared_mutex& mutex) = delete;

	public:
		virtual void reader_lock() noexcept override;
		virtual void writer_lock() noexcept override;
		virtual void reader_unlock() noexcept override;
		virtual void writer_unlock() noexcept override;
		virtual bool reader_try_lock() noexcept override;
		virtual bool writer_try_lock() noexcept override;
		virtual void* native_handle() noexcept override;

	private:
		std::shared_mutex mutex_;
	};

	ANIE_EXPORT mutex_base_ptr make_shared_mutex();

	class ANIE_EXPORT shared_mutex2 final : public mutex_base
	{
	public:
		shared_mutex2() = default;
		shared_mutex2(const shared_mutex2& mutex) = delete;
		shared_mutex2(shared_mutex2&& mutex) = delete;
		virtual ~shared_mutex2() override = default;

	public:
		shared_mutex2& operator=(const shared_mutex2& mutex) = delete;
		shared_mutex2& operator=(shared_mutex2&& mutex) = delete;
		bool operator==(const shared_mutex2& mutex) = delete;
		bool operator!=(const shared_mutex2& mutex) = delete;

	public:
		virtual void reader_lock() noexcept override;
		virtual void writer_lock() noexcept override;
		virtual void reader_unlock() noexcept override;
		virtual void writer_unlock() noexcept override;
		virtual bool reader_try_lock() noexcept override;
		virtual bool writer_try_lock() noexcept override;
		virtual void* native_handle() noexcept override;

	private:
		std::shared_mutex mutex_;
		std::atomic<std::size_t> waiting_writer_count_;
	};

	ANIE_EXPORT mutex_base_ptr make_shared_mutex2();

	class ANIE_EXPORT empty_mutex final : public mutex_base
	{
	public:
		empty_mutex() = default;
		empty_mutex(const empty_mutex& mutex) = delete;
		empty_mutex(empty_mutex&& mutex) = delete;
		virtual ~empty_mutex() override = default;

	public:
		empty_mutex& operator=(const empty_mutex& mutex) = delete;
		empty_mutex& operator=(empty_mutex&& mutex) = delete;
		bool operator==(const empty_mutex& mutex) = delete;
		bool operator!=(const empty_mutex& mutex) = delete;

	public:
		virtual void reader_lock() noexcept override;
		virtual void writer_lock() noexcept override;
		virtual void reader_unlock() noexcept override;
		virtual void writer_unlock() noexcept override;
		virtual bool reader_try_lock() noexcept override;
		virtual bool writer_try_lock() noexcept override;
		virtual void* native_handle() noexcept override;
	};

	ANIE_EXPORT mutex_base_ptr make_empty_mutex();

	class lock_guard final
	{
	public:
		explicit lock_guard(mutex_base_ptr& mutex) noexcept;
		lock_guard(const lock_guard& guard) = delete;
		lock_guard(lock_guard&& guard) = delete;
		~lock_guard();

	public:
		lock_guard& operator=(const lock_guard& guard) = delete;
		lock_guard& operator=(lock_guard&& guard) = delete;
		bool operator==(const lock_guard& guard) = delete;
		bool operator!=(const lock_guard& guard) = delete;

	private:
		mutex_base_ptr& mutex_;
	};

	class ANIE_EXPORT reader_lock_guard final
	{
	public:
		explicit reader_lock_guard(mutex_base_ptr& mutex) noexcept;
		reader_lock_guard(const reader_lock_guard& guard) = delete;
		reader_lock_guard(reader_lock_guard&& guard) = delete;
		~reader_lock_guard();

	public:
		reader_lock_guard& operator=(const reader_lock_guard& guard) = delete;
		reader_lock_guard& operator=(reader_lock_guard&& guard) = delete;
		bool operator==(const reader_lock_guard& guard) = delete;
		bool operator!=(const reader_lock_guard& guard) = delete;

	private:
		mutex_base_ptr& mutex_;
	};
}

#endif
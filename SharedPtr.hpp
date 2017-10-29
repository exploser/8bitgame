#pragma once
#include <cassert>
#include <utility>

namespace engine::utils
{
template <class T>
class SharedPtr
{
	template <typename U>
	friend class SharedPtr;

public:
	template <class ... U>
	static auto Make(U && ... u)
	{
		return SharedPtr<T>(new T{std::forward<U>(u) ...});
	}

	inline SharedPtr() :
		p_(nullptr),
		rc_(new int (1))
	{
	}

	inline SharedPtr(T *ptr) :
		p_(ptr),
		rc_(new int (1))
	{
	}

	inline SharedPtr(const SharedPtr<T> &rhs) :
		p_(rhs.p_),
		rc_(rhs.rc_)
	{
		assert(rc_);
		addref();
	}

	template <typename U>
	inline SharedPtr(const SharedPtr<U> &rhs) :
		p_(rhs.p_),
		rc_(rhs.rc_)
	{
		assert(rc_);
		addref();
	}

	inline ~SharedPtr()
	{
		assert(rc_);
		assert(*rc_ >= 1);

		if (deref() == 0)
		{
			free();
		}
	}

	T & operator* ()
	{
		return *p_;
	}

	const T & operator* () const
	{
		return *p_;
	}

	T * operator-> ()
	{
		return p_;
	}

	const T * operator-> () const
	{
		return p_;
	}

	operator bool() const
	{
		return p_;
	}

	SharedPtr<T> & operator= (const SharedPtr<T> &rhs)
	{
		if (this != &rhs)
		{
			if (deref() == 0)
			{
				free();
			}

			p_ = rhs.p_;
			rc_ = rhs.rc_;
			assert(rc_);
			addref();
		}

		return *this;
	}

private:
	void free()
	{
		if (p_)
		{
			delete p_;
			p_ = nullptr;
		}

		delete rc_;
		rc_ = nullptr;
	}

	void addref()
	{
		++(*rc_);
	}

	int deref()
	{
		return --(*rc_);
	}

private:
	T *p_;
	int *rc_;
};
}

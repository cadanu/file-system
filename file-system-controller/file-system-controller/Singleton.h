#ifndef SINGLETON_H
#define SINGLETON_H

template <typename T>
class Singleton
{
public:
	static T& Instance()
	{
		static T instance;
		return instance;
	}

protected:
	Singleton() { }
	virtual ~Singleton() { }

private:
	Singleton(Singleton const&) = delete;
	Singleton& operator=(Singleton const&) = delete;	
};

#endif// SINGLETON_H

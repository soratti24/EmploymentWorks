//////////////////////////////////
// ComPtr.h
// 
// 作成日：2023/06/09
//////////////////////////////////

#ifndef ___COM_PTR_H___
#define ___COM_PTR_H___

namespace Coms
{
	// コンポーネントの子であるか
	template <class T>
	using IsIUnknownChild = std::is_base_of<IUnknown, T>;

	template <typename T>
	struct ComPtr
	{
		static_assert(IsIUnknownChild<T>::value, "TはIUnknownを継承していません");

		ComPtr() { instance = nullptr; }
		ComPtr(T* in) { instance = in; }
		~ComPtr() { if (instance != nullptr) instance->Release(); }

		T* operator->() { return instance; }
		T* operator*() { return instance; }
		ComPtr& operator=(T* in)
		{
			if (instance != nullptr)
				instance->Release();
			instance = in;
			return *this;
		}

		T** get() { return &instance; }

		LPVOID* getLPVOID() { return (LPVOID*)&instance; }

		// 所有権を破棄する
		// @ Memo : インスタンスをリリースせずに手放します
		void release() { instance = nullptr; }

	private:
		ComPtr(const ComPtr& copy) {}
		ComPtr& operator=(const ComPtr& copy) {}

	private:
		T* instance;
	};
}

#endif // !___COM_PTR_H___
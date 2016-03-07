#ifndef __STRING_UTIL_H__
#define __STRING_UTIL_H__

#include <xstring>
using namespace System;
using namespace System::Runtime::InteropServices;

class StringUtil
{
public:
	static wchar_t* ToWcharPtr(System::String^ str)
	{
		/*if (str == nullptr || str->Length == 0)
		return nullptr;
		wchar_t* charp = new wchar_t[str->Length + 1];
		for (int i = 0; i < str->Length; i++)
		charp[i] = str[i];
		charp[str->Length] = L'\0';
		return charp;*/
		return (wchar_t*)Marshal::StringToHGlobalUni(str).ToPointer();
	}

	static char* ToCharPtr(System::String^ str)
	{
		return (char*)Marshal::StringToHGlobalAnsi(str).ToPointer();
	}

	static System::String^ ToClrString(const char* str)
	{
		return Marshal::PtrToStringAuto(IntPtr((void*)str));
	}

	static System::String^ ToClrString(const wchar_t* str)
	{
		return Marshal::PtrToStringAuto(IntPtr((void*)str));
	}

	static std::wstring& ToWstring(const wchar_t* chars_ptr)
	{
		if (!chars_ptr)
			return *new std::wstring();
		return *new std::wstring(chars_ptr);
	}

	static std::wstring& ToWstring(const System::String^ cstr)
	{
		auto str = const_cast<System::String^>(cstr);
		if (System::String::IsNullOrEmpty(str))
			return *new std::wstring();
		return ToWstring(ToWcharPtr(str));
	}
};

#endif // __STRING_UTIL_H__
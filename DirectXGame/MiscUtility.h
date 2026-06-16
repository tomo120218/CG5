#pragma once
#include <string>

class MiscUtility {};

// string => wstring文字列変換
std::wstring Convertstring(const std::string& str);

// wstring => string文字列変換
std::string ConvertString(const std::wstring& str);
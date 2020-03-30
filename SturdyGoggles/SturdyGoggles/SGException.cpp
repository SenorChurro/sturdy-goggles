#include "SGException.h"
#include <sstream>

SGException::SGException(int line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* SGException::what() const noexcept
{
	std::ostringstream oss;
	oss << GetType() << std::endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* SGException::GetType() const noexcept
{
	return "Sturdy Goggles Exception";
}

int SGException::GetLine() const noexcept
{
	return line;
}

const std::string& SGException::GetFile() const noexcept
{
	return file;
}

std::string SGException::GetOriginString() const noexcept
{
	std::ostringstream oss;
	oss << "[File] " << file << std::endl
		<< "[Line] " << line;
	return oss.str();
}

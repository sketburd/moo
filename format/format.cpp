#include "../include/format.h"




std::string jlo::format(const char* formatString, std::string value)
{
	return formatParse(formatString, value);
}
template<typename... Args>
std::string jlo::format(const char* formatString, std::string value, Args... args)
{
	return jlo::format(formatParse(formatString, value).c_str(), args...);
}




std::string jlo::format(const char* formatString, const char* value) 
{
	return formatParse(formatString, std::string(value));
}
template<typename... Args>
std::string jlo::format(const char* formatString, const char* value, Args... args)
{	
	return jlo::format(formatParse(formatString, std::string(value)).c_str(), args...);
}




std::string jlo::format(const char* formatString, int value)
{
	return formatParse(formatString, std::to_string(value));
}
template<typename... Args>
std::string jlo::format(const char* formatString, int value, Args... args)
{	
	return jlo::format(formatParse(formatString, std::to_string(value)).c_str(), args...);
}




std::string jlo::format(const char* formatString, long value)
{
	return formatParse(formatString, std::to_string(value));
}
template<typename... Args>
std::string jlo::format(const char* formatString, long value, Args... args)
{	
	return jlo::format(formatParse(formatString, std::to_string(value)).c_str(), args...);
}




std::string jlo::format(const char* formatString, long long value)
{
	return formatParse(formatString, std::to_string(value));
}
template<typename... Args>
std::string jlo::format(const char* formatString, long long value, Args... args)
{	
	return jlo::format(formatParse(formatString, std::to_string(value)).c_str(), args...);
}




std::string jlo::format(const char* formatString, unsigned value)
{
	return formatParse(formatString, std::to_string(value));
}
template<typename... Args>
std::string jlo::format(const char* formatString, unsigned value, Args... args)
{	
	return jlo::format(formatParse(formatString, std::to_string(value)).c_str(), args...);
}




std::string jlo::format(const char* formatString, unsigned long value)
{
	return formatParse(formatString, std::to_string(value));
}
template<typename... Args>
std::string jlo::format(const char* formatString, unsigned long value, Args... args)
{	
	return jlo::format(formatParse(formatString, std::to_string(value)).c_str(), args...);
}




std::string jlo::format(const char* formatString, unsigned long long value)
{
	return formatParse(formatString, std::to_string(value));
}
template<typename... Args>
std::string jlo::format(const char* formatString, unsigned long long value, Args... args)
{	
	return jlo::format(formatParse(formatString, std::to_string(value)).c_str(), args...);
}




std::string jlo::format(const char* formatString, float value)
{
	return formatParse(formatString, std::to_string(value));
}
template<typename... Args>
std::string jlo::format(const char* formatString, float value, Args... args)
{	
	return jlo::format(formatParse(formatString, std::to_string(value)).c_str(), args...);
}




std::string jlo::format(const char* formatString, double value)
{
	return formatParse(formatString, std::to_string(value));
}
template<typename... Args>
std::string jlo::format(const char* formatString, double value, Args... args)
{	
	return jlo::format(formatParse(formatString, std::to_string(value)).c_str(), args...);
} 
 
 
 
 
std::string jlo::format(const char* formatString, long double value)
{
	return formatParse(formatString, std::to_string(value));
}
template<typename... Args>
std::string jlo::format(const char* formatString, long double value, Args... args)
{	
	return jlo::format(formatParse(formatString, std::to_string(value)).c_str(), args...);
}




// Based on a picture of the Boyer–Moore string-search algorithm.
//
//                            P A N A M A -
//
//                            N A M - - - -
//                
//                            - N A M - - -
//
//                            - - N A M - -
//
//                            - - - N A M -
//
std::string jlo::formatParse(const char* formatString, std::string value)
{
	std::string retStr("");
	
	for (int index = 0; formatString[index + 1] != '\0' ; ++index)
	{
		if (formatString[index] == '{' && formatString[index + 1] == '}')
		{
			retStr += value;
			
			if (formatString[index + 2] != '\0')
			{			
				retStr += &(formatString[index + 2]);
			}

			return retStr;
		}
		
		retStr += formatString[index];
	}
	
	return retStr;
}

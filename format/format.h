// format.h: light "std::format / fmt" substitute.
#pragma once
#include <string>




// jlo::format is a function to simplify string formating.
//
// Args:
// - formatString (const char*) : The string model, contains "{}" to show where to insert
//                                arguments. 
// - args (Args...)             : The arguments to insert into formatString. They replace the "{}" 
//                                in the string model.
// 
//                                Valid arguments include:
// 
//                                    std::string
//                                    const char*
//                                    int	
//                                    long
//                                    long long
//                                    unsigned
//                                    unsigned long
//                                    unsigned long long 
//                                    float
//                                    double
//                                    long double
//                          
//
// Returns:
// - std::string: The string model with the inserted arguments.
//
// Examples:
// 
//     jlo::format("{} bars for sale! ${}", "Chocolate", 1);
//     - returns: "Chocolate bars for sale! $1"
//


namespace jlo
{


	inline std::string formatParse(const char* formatString, std::string value);	




	inline std::string format(const char* formatString, std::string value)
	{
		return formatParse(formatString, value);
	} 
	template<typename... Args>
	inline std::string format(const char* formatString, std::string value, Args... args)
	{
		return format(formatParse(formatString, value).c_str(), args...);
	}




	inline std::string format(const char* formatString, const char* value)
	{
		return formatParse(formatString, std::string(value));
	} 
	template<typename... Args>
	inline std::string format(const char* formatString, const char* value, Args... args)
	{	
		return format(formatParse(formatString, std::string(value)).c_str(), args...);
	}	




	inline std::string format(const char* formatString, int value)
	{
		return formatParse(formatString, std::to_string(value));
	}
	template<typename... Args>
	inline std::string format(const char* formatString, int value, Args... args)
	{	
		return format(formatParse(formatString, std::to_string(value)).c_str(), args...);
	}




	inline std::string format(const char* formatString, long value)
	{
		return formatParse(formatString, std::to_string(value));
	} 
	template<typename... Args>
	inline std::string format(const char* formatString, long value, Args... args)
	{	
		return format(formatParse(formatString, std::to_string(value)).c_str(), args...);
	}




	inline std::string format(const char* formatString, long long value)
	{
		return formatParse(formatString, std::to_string(value));
	}
	template<typename... Args>
	inline std::string format(const char* formatString, long long value, Args... args)
	{	
		return format(formatParse(formatString, std::to_string(value)).c_str(), args...);
	}




	inline std::string format(const char* formatString, unsigned value)
	{
		return formatParse(formatString, std::to_string(value));
	}
	template<typename... Args>
	inline std::string format(const char* formatString, unsigned value, Args... args)
	{	
		return format(formatParse(formatString, std::to_string(value)).c_str(), args...);
	}




	inline std::string format(const char* formatString, unsigned long value)
	{
		return formatParse(formatString, std::to_string(value));
	}
	template<typename... Args>
	inline std::string format(const char* formatString, unsigned long value, Args... args)
	{	
		return format(formatParse(formatString, std::to_string(value)).c_str(), args...);
	}




	inline std::string format(const char* formatString, unsigned long long value)
	{
		return formatParse(formatString, std::to_string(value));
	}
	template<typename... Args>
	inline std::string format(const char* formatString, unsigned long long value, Args... args)
	{	
		return format(formatParse(formatString, std::to_string(value)).c_str(), args...);
	}




	inline std::string format(const char* formatString, float value)
	{
		return formatParse(formatString, std::to_string(value));
	} 
	template<typename... Args>
	inline std::string format(const char* formatString, float value, Args... args)
	{	
		return format(formatParse(formatString, std::to_string(value)).c_str(), args...);
	}




	inline std::string format(const char* formatString, double value)
	{
		return formatParse(formatString, std::to_string(value));
	}
	template<typename... Args>
	inline std::string format(const char* formatString, double value, Args... args)
	{	
		return format(formatParse(formatString, std::to_string(value)).c_str(), args...);
	}




	inline std::string format(const char* formatString, long double value)
	{
		return formatParse(formatString, std::to_string(value));
	}
	template<typename... Args>
	inline std::string format(const char* formatString, long double value, Args... args)
	{	
		return format(formatParse(formatString, std::to_string(value)).c_str(), args...);
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
	inline std::string formatParse(const char* formatString, std::string value)
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


}








/* Unit Tests:

std::string a = "a";
const char* b = "b";
int c = 0;
long d = 1;
long long e = 2;
unsigned f = 3;
unsigned long g = 4;
unsigned long long h = 5;
float i = 6;
double j = 7;
long double k = 8;
	
	
std::cout << jlo::format("a:{}\nb:{}\n0:{}\n1:{}\n2:{}\n3:{}\n4:{}\n5:{}\n6.000000:{}\n7.000000:{}\n8.000000:{}\n", a, b, c, d, e, f, g, h, i, j, k);

// Expected Output:
// a:a
// b:b
// 0:0
// 1:1
// 2:2
// 3:3
// 4:4
// 5:5
// 6.000000:6.000000
// 7.000000:7.000000
// 8.000000:8.000000

*/

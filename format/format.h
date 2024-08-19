// format.h: light "std::format / fmt" substitute.
#pragma once
#include <string>




// moo::format is a function to simplify string formating.
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
//     moo::format("{} bars for sale! ${}", "Chocolate", 1);
//     - returns: "Chocolate bars for sale! $1"
//
// Online Help:
//
// 	https://ar13l-x07.github.io/moo/format.html
//


namespace moo
{

	
	inline std::string to_string(std::string arg)        { return arg;                 }
	inline std::string to_string(const char* arg)        { return std::string(arg);    }
	inline std::string to_string(char arg)               { return std::string(1, arg); }
	inline std::string to_string(int arg)                { return std::to_string(arg); }
	inline std::string to_string(long arg)               { return std::to_string(arg); }
	inline std::string to_string(long long arg)          { return std::to_string(arg); }
	inline std::string to_string(unsigned arg)           { return std::to_string(arg); }
	inline std::string to_string(unsigned long arg)      { return std::to_string(arg); }
	inline std::string to_string(unsigned long long arg) { return std::to_string(arg); }
	inline std::string to_string(float arg)              { return std::to_string(arg); }
	inline std::string to_string(double arg)             { return std::to_string(arg); }
	inline std::string to_string(long double arg)        { return std::to_string(arg); }
	
	
	
	
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
	
	
	
	
	template<typename T>	
	inline std::string format(const char* formatString, T t)
	{
		return formatParse(formatString, to_string(t));
	}
	template<typename T, typename... Args>
	inline std::string format(const char* formatString, T t, Args... args)
	{
		return format(formatParse(formatString, to_string(t)).c_str(), args...);
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
char m = '9';

std::cout << moo::format("a:{}\nb:{}\n0:{}\n1:{}\n2:{}\n3:{}\n4:{}\n5:{}\n6.000000:{}\n7.000000:{}\n8.000000:{}\n9:{}\n", a, b, c, d, e, f, g, h, i, j, k, m);


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
// 9:9

*/

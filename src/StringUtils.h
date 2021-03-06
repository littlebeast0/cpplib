#ifndef __CPPBRICK_STRINGUTIL_H__
#define __CPPBRICK_STRINGUTIL_H__

#include <string>
#include <vector>
#include <list>
#include <climits>
#include <stdarg.h>
#include <sstream>

namespace cppbrick {

    class StringUtils
    {
        public:

        /**
           Returns a string contructed from the a format specifier
           and a va_list of arguments, analogously to vprintf(3).
           @param format the format specifier.
           @param args the va_list of arguments.
        **/
        static std::string vform(const char* format, va_list args);
        static std::string format(const char* format, ...);
        /**
           Returns a string identical to the given string but without leading
           or trailing HTABs or spaces.
        **/
        static std::string trim(const std::string& s);

        /**
           splits a string into a vector of string segments based on the
           given delimiter.
           @param v The vector in which the segments will be stored. The vector
           will be emptied before storing the segments
           @param s The string to split into segments.
           @param delimiter The delimiter character
           @param maxSegments the maximum number of segments. Upon return
           v.size() <= maxSegments.  The string is scanned from left to right
           so v[maxSegments - 1] may contain a string containing the delimiter
           character.
	   @return The actual number of segments (limited by maxSegments).
        **/
        static unsigned int split(std::vector<std::string>& v, 
				  const std::string& s, char delimiter,
				  unsigned int maxSegments = INT_MAX);
        /**
           splits a string into string segments based on the given delimiter
           and assigns the segments through an output_iterator.
           @param output The output_iterator through which to assign the string
           segments. Typically this will be a back_insertion_iterator.
           @param s The string to split into segments.
           @param delimiter The delimiter character
           @param maxSegments The maximum number of segments.
           @return The actual number of segments (limited by maxSegments).
        **/
        template<typename T> 
        static unsigned int split(T& output,
                const std::string& s, char delimiter,
                unsigned int maxSegments = INT_MAX) 
       {
            std::string::size_type left = 0;
            unsigned int i;
            for(i = 1; i < maxSegments; i++) 
            {
                std::string::size_type right = s.find(delimiter, left);
                if (right == std::string::npos) 
                {
                    break;
                }
                *output++ = s.substr(left, right - left);
                left = right + 1;
            }
            
            *output++ = s.substr(left);
            return i;
        }

		static void split(const std::string str, const std::string delim, std::vector<std::string> &vecStr, int num=-1);
		static void split(const std::string str, const std::string delim, std::list<std::string> &lstStr, int num=-1);
		
		template < typename T > 
		std::string to_string( const T& n )
		{
			std::ostringstream stm ;
			stm << n ;
			return stm.str() ;
		}		
    };

 	
}// namespace cppbrick

#endif //__CPPBRICK_STRINGUTIL_H__
 

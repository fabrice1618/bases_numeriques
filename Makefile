test_base: test_base.cpp Base.h Base.cpp
	g++ -Wall -Werror -Wextra -o test_base test_base.cpp Base.cpp -lm

test_conversion: test_conversion.cpp Base.h Base.cpp Conversion.h Conversion.cpp
	g++ -Wall -Werror -Wextra -o test_conversion test_conversion.cpp Base.cpp Conversion.cpp -lm

combinaisons: combinaisons.cpp Base.h Base.cpp Conversion.h Conversion.cpp
	g++ -Wall -Werror -Wextra -o combinaisons combinaisons.cpp Base.cpp Conversion.cpp -lm

clean:
	rm test_base
	rm test_conversion
	rm combinaisons
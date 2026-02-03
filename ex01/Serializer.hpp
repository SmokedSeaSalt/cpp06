#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include "data.hpp"
#include <cstdint>

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator=(const Serializer& other);
		virtual ~Serializer() = 0;

		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t raw);

	private:

};

#endif // SERIALIZER_HPP
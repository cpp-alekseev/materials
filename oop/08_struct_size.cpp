#include<iostream>

// https://katecpp.github.io/struct-members-order/
// https://en.wikipedia.org/wiki/Data_structure_alignment

struct SEmpty {};

struct SRandomOrder
{
    uint8_t     m_byte1; // 1 byte
    uint64_t    m_long;  // 8 byte
    uint8_t     m_byte2; // 1 byte
    uint32_t    m_int;   // 4 byte
    uint8_t     m_byte3; // 1 byte
};

// Total useful: 15 byte

struct SRandomOrderPacked
{
    uint8_t     m_byte1;
    uint64_t    m_long;
    uint8_t     m_byte2;
    uint32_t    m_int;
    uint8_t     m_byte3;
} __attribute((packed))__;

struct SNiceOrder
{
    uint64_t    m_long;
    uint32_t    m_int;
    uint8_t     m_byte1;
    uint8_t     m_byte2;
    uint8_t     m_byte3;
};


int main() {
	std::cout << "sizeof(SEmpty): " << sizeof(SEmpty) << '\n';
	std::cout << "sizeof(SRandomOrder): " << sizeof(SRandomOrder) << '\n';
	std::cout << "sizeof(SRandomOrderPacked): " << sizeof(SRandomOrderPacked) << '\n';
	std::cout << "sizeof(SNiceOrder): " << sizeof(SNiceOrder) << '\n';
}

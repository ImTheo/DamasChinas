
#ifndef MD5_H 
#define MD5_H 

#include "Include.h"

/* Type define */
typedef unsigned char byte;
typedef unsigned int uint32;
typedef unsigned int uint4;

using std::string;
using std::ifstream;

/* MD5 declaration. */
class MD5 {
public:
/**
 * @brief Construct a new MD5 object
 * 
 */
	MD5();
	/**
	 * @brief Construct a new MD5 object
	 * 
	 * @param input 
	 * @param length 
	 */
	MD5(const void* input, size_t length);
	/**
	 * @brief Construct a new MD5 object
	 * 
	 * @param str 
	 */
	MD5(const string& str);
	/**
	 * @brief Construct a new MD5 object
	 * 
	 * @param in 
	 */
	MD5(ifstream& in);
	/**
	 * @brief 
	 * 
	 * @param input 
	 * @param length 
	 */
	void update(const void* input, size_t length);
	/**
	 * @brief 
	 * 
	 * @param str 
	 */
	void update(const string& str);
	/**
	 * @brief 
	 * 
	 * @param in 
	 */
	void update(ifstream& in);
	/**
	 * @brief 
	 * 
	 * @return const byte* 
	 */
	const byte* digest();
	/**
	 * @brief 
	 * 
	 * @return string 
	 */
	string toString();
/**
 * @brief 
 * 
 */
	void reset();

	inline uint4 rotate_left(uint4 x, int n);
	inline void FF(uint4& a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
	inline void GG(uint4& a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
	inline void HH(uint4& a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);
	inline void II(uint4& a, uint4 b, uint4 c, uint4 d, uint4 x, uint4 s, uint4 ac);

private:
	void update(const byte* input, size_t length);
	void final();
	void transform(const byte block[64]);
	void encode(const uint32* input, byte* output, size_t length);
	void decode(const byte* input, uint32* output, size_t length);
	string bytesToHexString(const byte* input, size_t length);

	/* class uncopyable */
	MD5(const MD5&);
	MD5& operator=(const MD5&);
private:
	uint32 _state[4]; /* state (ABCD) */
	uint32 _count[2]; /* number of bits, modulo 2^64 (low-order word first) */
	byte _buffer[64]; /* input buffer */
	byte _digest[16]; /* message digest */
	bool _finished; /* calculate finished ? */

	static const byte PADDING[64]; /* padding for calculate */
	static const char HEX[16];
	static const size_t BUFFER_SIZE = 1024;
};

string FileDigest(const string& file);

#endif/*MD5_H*/
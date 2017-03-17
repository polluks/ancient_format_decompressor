/* Copyright (C) Teemu Suutari */

#ifndef FASTDECOMPRESSOR_HPP
#define FASTDECOMPRESSOR_HPP

#include "Decompressor.hpp"

// XPK sub-decompressor
class FASTDecompressor : public Decompressor
{
public:
	FASTDecompressor(uint32_t hdr,const Buffer &packedData);

	virtual ~FASTDecompressor();

	virtual bool isValid() const override final;
	virtual bool verifyPacked() const override final;
	virtual bool verifyRaw(const Buffer &rawData) const override final;

	virtual size_t getPackedSize() const override final;
	virtual size_t getRawSize() const override final;

	virtual bool decompress(Buffer &rawData) override final;

	static bool detectHeaderXPK(uint32_t hdr);

protected:
	virtual const std::string &getSubName() const override final;

private:
	bool		_isValid=false;
};

#endif
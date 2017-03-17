/* Copyright (C) Teemu Suutari */

#include "Decompressor.hpp"

#include "CRMDecompressor.hpp"
#include "DEFLATEDecompressor.hpp"
#include "IMPDecompressor.hpp"
#include "RNCDecompressor.hpp"
#include "TPWMDecompressor.hpp"
#include "XPKMaster.hpp"

Decompressor::Decompressor(const Buffer &packedData) :
	_packedData(packedData)
{
	// nothing needed
}

Decompressor::~Decompressor()
{
	// nothing needed
}

const std::string &Decompressor::getName() const
{
	static std::string name="<invalid>";
	return name;
}

const std::string &Decompressor::getSubName() const
{
	static std::string name="<invalid>";
	return name;
}

Decompressor *CreateDecompressor(const Buffer &packedData)
{
	uint32_t hdr;
	if (!packedData.readBE(0,hdr)) return nullptr;

	if (CRMDecompressor::detectHeader(hdr))
		return new CRMDecompressor(packedData);
	if (DEFLATEDecompressor::detectHeader(hdr))
		return new DEFLATEDecompressor(packedData);
	if (IMPDecompressor::detectHeader(hdr))
		return new IMPDecompressor(packedData);
	if (RNCDecompressor::detectHeader(hdr))
		return new RNCDecompressor(packedData);
	if (TPWMDecompressor::detectHeader(hdr))
		return new TPWMDecompressor(packedData);
	if (XPKMaster::detectHeader(hdr))
		return new XPKMaster(packedData);

	return nullptr;
}
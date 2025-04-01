#include "pch.h"
#include "Enums.h"

ERotateType& operator++ (ERotateType& _Rotate)
{
	int Value = static_cast<int>(_Rotate);
	++Value;
	if (Value == static_cast<int>(ERotateType::END))
		return _Rotate = ERotateType::NONE;
	return _Rotate = static_cast<ERotateType>(Value);
}

ERotateType& operator-- (ERotateType& _Rotate)
{
	int Value = static_cast<int>(_Rotate);
	--Value;
	if (Value < 0)
		return _Rotate = ERotateType::LEFT;
	return _Rotate = static_cast<ERotateType>(Value);
}
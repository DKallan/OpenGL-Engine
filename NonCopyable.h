#pragma once
#ifndef _NON_COPYABLE_H_
#define _NON_COPYABLE_H_

struct NonCopyable
{
	NonCopyable() = default;
	NonCopyable(const NonCopyable&) = delete;
	NonCopyable& operator=(const NonCopyable&) = delete;
};

#endif // !_NON_COPYABLE_H_

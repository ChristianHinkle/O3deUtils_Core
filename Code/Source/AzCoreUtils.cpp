
#include <O3deUtils/Core/AzCoreUtils.h>
#include <O3deUtils/Core/AzCoreUtils.inl>

namespace O3deUtils
{
    namespace Detail
    {
        template <AZStd::size_t maxStringSize, StdReimpl::integral TInteger>
        AZStd::fixed_string<maxStringSize> IntegerToString(TInteger num);
    }
}

namespace O3deUtils
{
    AZStd::fixed_string<24> EntityIdToString(AZ::EntityId entityId)
    {
        return IntegerToString(entityId.operator AZ::u64());
    }

    AZStd::fixed_string<24> IntegerToString(AZ::u64 num)
    {
        return Detail::IntegerToString<24>(num);
    }
    AZStd::fixed_string<24> IntegerToString(AZ::s64 num)
    {
        return Detail::IntegerToString<24>(num);
    }

    AZStd::fixed_string<16> IntegerToString(AZ::u32 num)
    {
        return Detail::IntegerToString<16>(num);
    }
    AZStd::fixed_string<16> IntegerToString(AZ::s32 num)
    {
        return Detail::IntegerToString<16>(num);
    }

    AZStd::fixed_string<8> IntegerToString(AZ::u16 num)
    {
        return Detail::IntegerToString<8>(num);
    }
    AZStd::fixed_string<8> IntegerToString(AZ::s16 num)
    {
        return Detail::IntegerToString<8>(num);
    }

    AZStd::fixed_string<4> IntegerToString(AZ::u8 num)
    {
        return Detail::IntegerToString<4>(num);
    }
    AZStd::fixed_string<4> IntegerToString(AZ::s8 num)
    {
        return Detail::IntegerToString<4>(num);
    }

    namespace Detail
    {
        template <AZStd::size_t maxStringSize, StdReimpl::integral TInteger>
        AZStd::fixed_string<maxStringSize> IntegerToString(TInteger num)
        {
            AZStd::fixed_string<maxStringSize> result;
            AZStd::to_string(result, num);
            return result;
        }
    }
}

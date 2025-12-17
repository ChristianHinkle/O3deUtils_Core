
#pragma once

#include <O3deUtils_Core/O3deUtils_CoreTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace O3deUtils_Core
{
    class O3deUtils_CoreRequests
    {
    public:
        AZ_RTTI(O3deUtils_CoreRequests, O3deUtils_CoreRequestsTypeId);
        virtual ~O3deUtils_CoreRequests() = default;
        // Put your public methods here
    };

    class O3deUtils_CoreBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using O3deUtils_CoreRequestBus = AZ::EBus<O3deUtils_CoreRequests, O3deUtils_CoreBusTraits>;
    using O3deUtils_CoreInterface = AZ::Interface<O3deUtils_CoreRequests>;

} // namespace O3deUtils_Core

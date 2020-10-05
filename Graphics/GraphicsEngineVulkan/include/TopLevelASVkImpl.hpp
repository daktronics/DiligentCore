/*
 *  Copyright 2019-2020 Diligent Graphics LLC
 *  Copyright 2015-2019 Egor Yusov
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *      http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 *  In no event and under no legal theory, whether in tort (including negligence), 
 *  contract, or otherwise, unless required by applicable law (such as deliberate 
 *  and grossly negligent acts) or agreed to in writing, shall any Contributor be
 *  liable for any damages, including any direct, indirect, special, incidental, 
 *  or consequential damages of any character arising as a result of this License or 
 *  out of the use or inability to use the software (including but not limited to damages 
 *  for loss of goodwill, work stoppage, computer failure or malfunction, or any and 
 *  all other commercial damages or losses), even if such Contributor has been advised 
 *  of the possibility of such damages.
 */

#pragma once

/// \file
/// Definition of the Diligent::TopLevelASVkImpl class

#include "RenderDeviceVk.h"
#include "RenderDeviceVkImpl.hpp"
#include "TopLevelASVk.h"
#include "TopLevelASBase.hpp"
#include "VulkanUtilities/VulkanObjectWrappers.hpp"

namespace Diligent
{

class TopLevelASVkImpl final : public TopLevelASBase<ITopLevelASVk, RenderDeviceVkImpl>
{
public:
    using TTopLevelASBase = TopLevelASBase<ITopLevelASVk, RenderDeviceVkImpl>;

    TopLevelASVkImpl(IReferenceCounters*   pRefCounters,
                     RenderDeviceVkImpl*   pRenderDeviceVk,
                     const TopLevelASDesc& Desc,
                     bool                  bIsDeviceInternal = false);
    ~TopLevelASVkImpl();

    virtual ScratchBufferSizes DILIGENT_CALL_TYPE GetScratchBufferSizes() const override { return m_ScratchSize; }

    virtual VkAccelerationStructureKHR DILIGENT_CALL_TYPE GetVkTLAS() const override { return m_VulkanTLAS; }

    virtual VkDeviceAddress DILIGENT_CALL_TYPE GetVkDeviceAddress() const override { return m_DeviceAddress; }

    IMPLEMENT_QUERY_INTERFACE_IN_PLACE(IID_TopLevelASVk, TTopLevelASBase);

private:
    VkDeviceAddress                         m_DeviceAddress = 0;
    VulkanUtilities::AccelStructWrapper     m_VulkanTLAS;
    VulkanUtilities::VulkanMemoryAllocation m_MemoryAllocation;
    ScratchBufferSizes                      m_ScratchSize;
};

} // namespace Diligent
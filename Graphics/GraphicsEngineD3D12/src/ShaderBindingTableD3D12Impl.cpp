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

#include "pch.h"
#include "ShaderBindingTableD3D12Impl.hpp"
#include "RenderDeviceD3D12Impl.hpp"
#include "DeviceContextD3D12Impl.hpp"
#include "D3D12TypeConversions.hpp"
#include "GraphicsAccessories.hpp"
#include "DXGITypeConversions.hpp"
#include "EngineMemory.h"
#include "StringTools.hpp"

namespace Diligent
{

ShaderBindingTableD3D12Impl::ShaderBindingTableD3D12Impl(IReferenceCounters*           pRefCounters,
                                                         class RenderDeviceD3D12Impl*  pDeviceD3D12,
                                                         const ShaderBindingTableDesc& Desc,
                                                         bool                          bIsDeviceInternal) :
    TShaderBindingTableBase{pRefCounters, pDeviceD3D12, Desc, bIsDeviceInternal}
{
}

ShaderBindingTableD3D12Impl::~ShaderBindingTableD3D12Impl()
{
}

IMPLEMENT_QUERY_INTERFACE(ShaderBindingTableD3D12Impl, IID_ShaderBindingTableD3D12, TShaderBindingTableBase)

void ShaderBindingTableD3D12Impl::ResetHitGroups(Uint32 HitShadersPerInstance)
{
    // AZ TODO
}

void ShaderBindingTableD3D12Impl::BindAll(const BindAllAttribs& Attribs)
{
    // AZ TODO
}

} // namespace Diligent
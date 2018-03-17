/*     Copyright 2015-2018 Egor Yusov
 *  
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 * 
 *     http://www.apache.org/licenses/LICENSE-2.0
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF ANY PROPRIETARY RIGHTS.
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
/// Declaration of Diligent::ShaderVkImpl class

#include "RenderDeviceVk.h"
#include "ShaderVk.h"
#include "ShaderBase.h"
#include "ShaderResourceLayoutVk.h"

#ifdef _DEBUG
#   define VERIFY_SHADER_BINDINGS
#endif

namespace Diligent
{

class ResourceMapping;
class FixedBlockMemoryAllocator;

/// Implementation of the Diligent::IShaderVk interface
class ShaderVkImpl : public ShaderBase<IShaderVk, IRenderDeviceVk>
{
public:
    typedef ShaderBase<IShaderVk, IRenderDeviceVk> TShaderBase;

    ShaderVkImpl(IReferenceCounters *pRefCounters, class RenderDeviceVkImpl *pRenderDeviceVk, const ShaderCreationAttribs &ShaderCreationAttribs);
    ~ShaderVkImpl();
    
    //virtual void QueryInterface( const Diligent::INTERFACE_ID &IID, IObject **ppInterface )override;

    virtual void BindResources( IResourceMapping* pResourceMapping, Uint32 Flags )override;
    
    virtual IShaderVariable* GetShaderVariable(const Char* Name)override;

/*
    ID3DBlob* GetShaderByteCode(){return m_pShaderByteCode;}
    const std::shared_ptr<const ShaderResourcesVk>& GetShaderResources()const{return m_pShaderResources;}
    const ShaderResourceLayoutVk& GetConstResLayout()const{return m_StaticResLayout;}

#ifdef VERIFY_SHADER_BINDINGS
    void DbgVerifyStaticResourceBindings();
#endif

private:

    DummyShaderVariable m_DummyShaderVar; ///< Dummy shader variable

    // ShaderResources class instance must be referenced through the shared pointer, because 
    // it is referenced by ShaderResourceLayoutVk class instances
    std::shared_ptr<const ShaderResourcesVk> m_pShaderResources;
    ShaderResourceLayoutVk m_StaticResLayout;
    ShaderResourceCacheVk m_ConstResCache;
*/
};

}
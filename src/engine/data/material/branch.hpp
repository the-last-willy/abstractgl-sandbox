#pragma once

#include "dependencies.hpp"

inline
auto make_branch_material() {
    auto material = Material();
    { // Capabilities.
        material.capabilities.insert(
            end(material.capabilities),
            {
                agl::Capability::cull_face,
                agl::Capability::depth_test,
                agl::Capability::line_smooth,
            });
    }
    { // Parameters.
        material.parameters.push_back([]() {
            glCullFace(GL_BACK);
            glDepthFunc(GL_LESS);
        });
    }
    { // Program.
        auto& p = material.program;
        auto shaders = std::map<agl::ShaderType, std::string>{
            {
                agl::vertex_shader_tag,
                agl::standard::string(root + "shader/tree/phong.vs")
            },
            {
                agl::fragment_shader_tag,
                agl::standard::string(root + "shader/tree/phong.fs")
            },
        };
        for(auto& [type, src] : shaders) {
            auto s = agl::shader(type);
            agl::source(s, src);
            agl::compile(s);
            agl::attach(p, s);
            agl::delete_(s);
        }
        agl::link(p);
    }
    return material;
}

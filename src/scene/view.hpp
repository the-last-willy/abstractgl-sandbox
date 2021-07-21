#pragma once

#include "agl/all.hpp"

namespace tlw {

struct View {
	agl::Vec<GLfloat, 3> rotation_center = agl::vec3(0.f, 0.f, 0.f);
	agl::Vec<GLfloat, 3> position = agl::vec3(0.f, 0.f, 0.f);

	// Aircraft rotation.
	float yaw = 0.f;
	float pitch = 0.f;
};

constexpr
auto transform(const View& v) {
	return agl::translation(v.position)
		* agl::rotation_y(v.yaw)
		* agl::rotation_x(v.pitch)
		* agl::translation(v.rotation_center);
}

}
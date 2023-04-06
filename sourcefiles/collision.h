/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef COLLISION_H
#define COLLISION_H

#include "library.h"

namespace Collide {

	bool CirclePoint(const Math::vec2* center,
		int diameter,
		const Math::vec2* point);

	bool LinePoint(Math::vec2* point,
		Math::vec2* line_p1,
		Math::vec2* line_p2);

	bool LineLine(Math::vec2* p1,
		Math::vec2* p2,
		Math::vec2* p3,
		Math::vec2* p4);

	bool CircleLine(const Math::vec2* center,
		int diameter,
		const Math::vec2* point1,
		const Math::vec2* point2,
		std::vector<Math::vec2>* collide_points);

}


#endif

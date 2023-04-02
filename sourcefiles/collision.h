/*
	GAM150 prototype
	Guyot
	Hankyung Lee
*/

#ifndef COLLISION_H
#define COLLISION_H

#include "library.h"

namespace Collide {

	bool LinePoint(	Math::vec2* point, 
					Math::vec2* line_p1, 
					Math::vec2* line_p2);

	bool CircleLine(const Math::vec2* center, 
					int d, 
					const Math::vec2* point1, 
					const Math::vec2* point2, 
					std::vector<Math::vec2>* collide_points);

}


#endif

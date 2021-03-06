#pragma once

#include <cassert>
#include <ostream>

#include "DataStructures/Graph/Attributes/AbstractAttribute.h"
#include "Tools/EnumParser.h"

// Road categories defined by OpenStreetMap.
enum class OsmRoadCategory {
  MOTORWAY,
  MOTORWAY_LINK,
  TRUNK,
  TRUNK_LINK,
  PRIMARY,
  PRIMARY_LINK,
  SECONDARY,
  SECONDARY_LINK,
  TERTIARY,
  TERTIARY_LINK,
  UNCLASSIFIED,
  RESIDENTIAL,
  LIVING_STREET,
  ROAD,
};

// Make EnumParser usable with OsmRoadCategory.
template <>
void EnumParser<OsmRoadCategory>::initNameToEnumMap() {
  nameToEnum = {
    {"motorway",       OsmRoadCategory::MOTORWAY},
    {"motorway_link",  OsmRoadCategory::MOTORWAY_LINK},
    {"trunk",          OsmRoadCategory::TRUNK},
    {"trunk_link",     OsmRoadCategory::TRUNK_LINK},
    {"primary",        OsmRoadCategory::PRIMARY},
    {"primary_link",   OsmRoadCategory::PRIMARY_LINK},
    {"secondary",      OsmRoadCategory::SECONDARY},
    {"secondary_link", OsmRoadCategory::SECONDARY_LINK},
    {"tertiary",       OsmRoadCategory::TERTIARY},
    {"tertiary_link",  OsmRoadCategory::TERTIARY_LINK},
    {"unclassified",   OsmRoadCategory::UNCLASSIFIED},
    {"residential",    OsmRoadCategory::RESIDENTIAL},
    {"living_street",  OsmRoadCategory::LIVING_STREET},
    {"road",           OsmRoadCategory::ROAD}
  };
}

// Writes the character representation of the specified OSM road category to the given stream.
inline std::ostream& operator<<(std::ostream& os, const OsmRoadCategory cat) {
  switch (cat) {
    case OsmRoadCategory::MOTORWAY:       os << "motorway";       break;
    case OsmRoadCategory::MOTORWAY_LINK:  os << "motorway_link";  break;
    case OsmRoadCategory::TRUNK:          os << "trunk";          break;
    case OsmRoadCategory::TRUNK_LINK:     os << "trunk_link";     break;
    case OsmRoadCategory::PRIMARY:        os << "primary";        break;
    case OsmRoadCategory::PRIMARY_LINK:   os << "primary_link";   break;
    case OsmRoadCategory::SECONDARY:      os << "secondary";      break;
    case OsmRoadCategory::SECONDARY_LINK: os << "secondary_link"; break;
    case OsmRoadCategory::TERTIARY:       os << "tertiary";       break;
    case OsmRoadCategory::TERTIARY_LINK:  os << "tertiary_link";  break;
    case OsmRoadCategory::UNCLASSIFIED:   os << "unclassified";   break;
    case OsmRoadCategory::RESIDENTIAL:    os << "residential";    break;
    case OsmRoadCategory::LIVING_STREET:  os << "living_street";  break;
    case OsmRoadCategory::ROAD:           os << "road";           break;
  }
  return os;
}

// An attribute associating an OSM road category with each edge of a graph.
class OsmRoadCategoryAttribute : public AbstractAttribute<OsmRoadCategory> {
 public:
  // Returns the attribute's default value.
  static Type defaultValue() {
    return OsmRoadCategory::ROAD;
  }

  // Returns the OSM road category of edge e.
  const Type& osmRoadCategory(const int e) const {
    assert(e >= 0); assert(e < values.size());
    return values[e];
  }

  // Returns a reference to the OSM road category of edge e.
  Type& osmRoadCategory(const int e) {
    assert(e >= 0); assert(e < values.size());
    return values[e];
  }

 protected:
  static constexpr const char* NAME = "osm_road_category"; // The attribute's unique name.
};

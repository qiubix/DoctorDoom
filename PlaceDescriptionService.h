#ifndef PlaceDescriptionService_h
#define PlaceDescriptionService_h

#include <string>
#include "Address.h"

class Http;

class PlaceDescriptionService {
public:
   PlaceDescriptionService(Http* http);
   std::string summaryDescription(const std::string& latitude, const std::string& longitude) const;

private:
   Http* http_;
};

#endif

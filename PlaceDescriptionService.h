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
   std::string keyValue(const std::string& key, const std::string& value) const;

   Http* http_;
};

#endif

#include "moja/filesystem.h"

#include <Poco/Path.h>

namespace moja {

filesystem::path expand(const std::string& path) { return Poco::Path::expand(path); }

filesystem::path expand(const filesystem::path& path) { return expand(path.string()); }

}  // namespace moja::filesystem
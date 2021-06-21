#pragma once

#include "_core_exports.h"

#include <filesystem>

namespace moja{
namespace filesystem {
using namespace std::filesystem;
}

filesystem::path CORE_API expand(const std::string& path);
filesystem::path CORE_API expand(const filesystem::path& path);

}  // namespace moja::filesystem

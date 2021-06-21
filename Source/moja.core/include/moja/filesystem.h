#pragma once

#include "_core_exports.h"

#include <filesystem>

namespace moja::filesystem {

using namespace std::filesystem;

path CORE_API expand(const std::string& path);
path CORE_API expand(const path& path);

}  // namespace moja::filesystem

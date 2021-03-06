#pragma once

#include <src/semi-gcode.hpp>
#include <functional>

enum class upload_instruction_ret {
	keep_going,
	cancel
};

struct gcode_generation_options {
	double dpi{150.0};
};

using upload_instruction = std::function<upload_instruction_ret(std::string &&gcode, double)>;

void generate_gcode(semi::gcodes &&gcodes, const gcode_generation_options &opts, const upload_instruction &instruction);

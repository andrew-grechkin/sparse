#include "config.hpp"

#include <argp.h>
#include <cstdlib>
#include <unistd.h>

const char *argp_program_version = "v1.0.0";
const char *argp_program_bug_address = "Andrew Grechkin <andrew.grechkin@gmail.com>";

auto args_doc = "FILE";
auto doc = "sparse -- a simple tool to pipe standard input into a sparse file";

const argp_option options[] = {
	{"input",    'i', "FILE", 0,            "Input from FILE instead of standard input" },
	{"verbose",  'v', 0,      0,            "Produce verbose output" },
	{ 0 },
};

error_t parse_opt(int key, char *arg, struct argp_state *state) {
	auto args = static_cast<Config*>(state->input);
	switch (key) {
	case 'v':
		args->verbose = 1;
		break;
	case 'i':
		args->input_file = arg;
		break;
	case ARGP_KEY_NO_ARGS:
		argp_usage(state);
	case ARGP_KEY_ARG:
		args->file = arg;
		state->next = state->argc;
		break;
	default:
		return ARGP_ERR_UNKNOWN;
	}
	return 0;
}

const argp argp = { options, parse_opt, args_doc, doc, 0, 0, 0 };

int Config::parse(int argc, char ** argv)
{
	buf_size = getpagesize();
	return argp_parse(&argp, argc, argv, 0, nullptr, this);
}

Config& Config::get()
{
	static Config inst;
	return inst;
}

from os.path import isdir, join

from SCons.Script import DefaultEnvironment

env = DefaultEnvironment()
platform = env.PioPlatform()
board = env.BoardConfig()

API_DIR = platform.get_package_dir("framework-arduino-api")
LT_API_DIR = join(platform.get_dir(), "arduino", "libretuya")
assert isdir(API_DIR)
assert isdir(LT_API_DIR)

# Includes
env.Prepend(
    CPPPATH=[
        # fmt: off
        join(API_DIR),
        join(API_DIR, "api", "deprecated"),
        join(LT_API_DIR),
        join(LT_API_DIR, "compat"),
        join(LT_API_DIR, "libraries", "base64"),
        join(LT_API_DIR, "libraries", "HTTPClient"),
        join(LT_API_DIR, "libraries", "WiFiMulti"),
        # fmt: on
    ],
    CPPDEFINES=[
        ("LT_VERSION", platform.version),
        ("LT_BOARD", board.get("build.variant")),
    ],
)

sources_api = [
    # fmt: off
	"+<" + API_DIR + "/api/Common.cpp>",
	"+<" + API_DIR + "/api/IPAddress.cpp>",
	"+<" + API_DIR + "/api/PluggableUSB.cpp>",
	"+<" + API_DIR + "/api/Print.cpp>",
	"+<" + API_DIR + "/api/Stream.cpp>",
	"+<" + API_DIR + "/api/String.cpp>",
    "+<" + LT_API_DIR + "/api/*.c*>",
    "+<" + LT_API_DIR + "/libraries/**/*.c*>",
    # fmt: on
]

# Arduino API library target
target_api = env.BuildLibrary(
    join("$BUILD_DIR", "arduino_api"),
    API_DIR,
    sources_api,
)
env.Prepend(LIBS=[target_api])
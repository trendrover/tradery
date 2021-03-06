/*
	 Copyright (C) 2018-2020 Adrian Michel

	 Licensed under the Apache License, Version 2.0 (the "License");
	 you may not use this file except in compliance with the License.
	 You may obtain a copy of the License at

			 http://www.apache.org/licenses/LICENSE-2.0

	 Unless required by applicable law or agreed to in writing, software
	 distributed under the License is distributed on an "AS IS" BASIS,
	 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
	 See the License for the specific language governing permissions and
	 limitations under the License.
*/

#pragma once

#include <fstream>
#include <boost\algorithm\string\replace.hpp>
#include "path.h"
#include <Log.h>
#include <logger.h>


class TestPath : public Path {
private:
	std::string init(const std::string& value) {
		std::string p(value);
		boost::replace_all(p, "\"", "");
		return p;
	}

public:
	TestPath(const std::string& value)
		: Path(init(value)) {}
};


class TestDataPath : public TestPath {
public:
	TestDataPath()
		: TestPath(EXPAND(TEST_DATA_PATH)) {}
};


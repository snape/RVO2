<!--
QUALITY_DECLARATION.md
RVO2 Library

SPDX-FileCopyrightText: 2008 University of North Carolina at Chapel Hill
SPDX-License-Identifier: CC-BY-SA-4.0

Creative Commons Attribution-ShareAlike 4.0 International Public License

You are free to:

* Share -- copy and redistribute the material in any medium or format

* ShareAlike -- If you remix, transform, or build upon the material, you must
  distribute your contributions under the same license as the original

* Adapt -- remix, transform, and build upon the material for any purpose, even
  commercially.

The licensor cannot revoke these freedoms as long as you follow the license
terms.

Under the following terms:

* Attribution -- You must give appropriate credit, provide a link to the
  license, and indicate if changes were made. You may do so in any reasonable
  manner, but not in any way that suggests the licensor endorses you or your
  use.

* No additional restrictions -- You may not apply legal terms or technological
  measures that legally restrict others from doing anything the license
  permits.

Notices:

* You do not have to comply with the license for elements of the material in
  the public domain or where your use is permitted by an applicable exception
  or limitation.

* No warranties are given. The license may not give you all of the permissions
  necessary for your intended use. For example, other rights such as publicity,
  privacy, or moral rights may limit how you use the material.

Please send all bug reports to <geom@cs.unc.edu>.

The authors may be contacted via:

Jur van den Berg, Stephen J. Guy, Jamie Snape, Ming C. Lin, Dinesh Manocha
Dept. of Computer Science
201 S. Columbia St.
Frederick P. Brooks, Jr. Computer Science Bldg.
Chapel Hill, N.C. 27599-3175
United States of America

<https://gamma.cs.unc.edu/RVO2/>
-->

# `RVO2 Library` Quality Declaration

The package `RVO2 Library` claims to be in the **Quality Level 2** category.

Below are the rationales, notes, and caveats for this claim, organized by each
requirement listed in the Package Requirements for Quality Level 2 in
[REP-2004](https://www.ros.org/reps/rep-2004.html).

## Version Policy [1]

### Version Scheme [1.i]

`RVO2 Library` uses [Semantic Versioning 2.0.0](https://semver.org/), and is
at version `2.0.3`. The version is declared in `CMakeLists.txt`,
`MODULE.bazel`, and `meson.build`.

### Version Stability [1.ii]

`RVO2 Library` is at a stable version (`2.0.3`), which is greater than
`1.0.0`.

### Public API Declaration [1.iii]

The public API of `RVO2 Library` is the set of symbols declared in
[`src/RVO.h`](src/RVO.h). This header aggregates the public interfaces of
`RVOSimulator`, `Vector2`, and `Line`. Internal implementation details in
`Agent`, `KdTree`, and `Obstacle` are not part of the public API.

### API Stability Within a Released Version [1.iv]

The public API is stable across patch and minor versions. Breaking API changes
are only introduced in new major versions.

### ABI Stability Within a Released Version [1.v]

ABI compatibility is maintained across patch versions within the same
`major.minor` release series. New major or minor versions may introduce
ABI-breaking changes.

## Change Control Process [2]

### Change Requests [2.i]

All changes to `RVO2 Library` are submitted through pull requests on
[GitHub](https://github.com/snape/RVO2). Direct commits to the `main` branch
are not permitted outside of automated tooling.

### Contributor Origin [2.ii]

All contributors must sign off on their commits using the
[Developer Certificate of Origin (DCO)](https://developercertificate.org/),
enforced via the DCO GitHub App on every pull request.

### Peer Review Policy [2.iii]

As a single-maintainer project, all changes are reviewed by the primary
maintainer [@snape](https://github.com/snape) before merging.

### Continuous Integration [2.iv]

CI is performed via GitHub Actions on every push and pull request to `main`,
and on a daily or weekly schedule:

- [`.github/workflows/actionlint.yml`](.github/workflows/actionlint.yml):
  validates GitHub Actions workflow files with actionlint.
- [`.github/workflows/bazel.yml`](.github/workflows/bazel.yml): builds and
  tests with Bazel on AlmaLinux, Arch Linux, Fedora, openSUSE, and Ubuntu
  (amd64 and arm64), and macOS (arm64). Alpine Linux is excluded due to musl
  libc incompatibility with Bazel.
- [`.github/workflows/buildifier.yml`](.github/workflows/buildifier.yml):
  enforces Bazel file formatting with buildifier.
- [`.github/workflows/check-jsonschema.yml`](.github/workflows/check-jsonschema.yml):
  validates [`compose.yaml`](compose.yaml) and [`renovate.json`](renovate.json)
  against their respective schemas.
- [`.github/workflows/clang-format.yml`](.github/workflows/clang-format.yml):
  enforces code formatting via clang-format.
- [`.github/workflows/clang-tidy.yml`](.github/workflows/clang-tidy.yml):
  runs clang-tidy static analysis with warnings as errors.
- [`.github/workflows/cmake.yml`](.github/workflows/cmake.yml): builds and
  tests with CMake on AlmaLinux, Alpine Linux, Arch Linux, Fedora, openSUSE
  Leap, Ubuntu (amd64 and arm64), macOS (arm64), and Windows (amd64),
  enabling `BUILD_TESTING`, `ENABLE_HARDENING`, `ENABLE_OPENMP`, and
  `WARNINGS_AS_ERRORS`.
- [`.github/workflows/codeql.yml`](.github/workflows/codeql.yml): runs GitHub
  CodeQL semantic code analysis for C++ on a weekly schedule.
- [`.github/workflows/codespell.yml`](.github/workflows/codespell.yml):
  checks spelling in source files and documentation with codespell.
- [`.github/workflows/coverage.yml`](.github/workflows/coverage.yml):
  measures code coverage with gcovr, publishes an XML report, and uploads
  results to DeepSource on each push to `main`.
- [`.github/workflows/cppcheck.yml`](.github/workflows/cppcheck.yml): runs
  cppcheck static analysis with all checks enabled; results are uploaded to
  GitHub Code Scanning as SARIF.
- [`.github/workflows/cpplint.yml`](.github/workflows/cpplint.yml): enforces
  Google C++ style with cpplint.
- [`.github/workflows/detect-secrets.yml`](.github/workflows/detect-secrets.yml):
  scans for accidentally committed secrets against a maintained baseline.
- [`.github/workflows/docker.yml`](.github/workflows/docker.yml): builds the
  development environment Docker image on a weekly schedule.
- [`.github/workflows/gersemi.yml`](.github/workflows/gersemi.yml): enforces
  CMake file formatting with gersemi.
- [`.github/workflows/hadolint.yml`](.github/workflows/hadolint.yml): lints
  the Dockerfile with hadolint.
- [`.github/workflows/iwyu.yml`](.github/workflows/iwyu.yml): checks include
  hygiene with include-what-you-use.
- [`.github/workflows/lizard.yml`](.github/workflows/lizard.yml): measures
  cyclomatic complexity with lizard.
- [`.github/workflows/meson.yml`](.github/workflows/meson.yml): builds and
  tests with Meson on AlmaLinux, Alpine Linux, Arch Linux, Fedora, openSUSE
  Leap, Ubuntu (amd64 and arm64), macOS (arm64), and Windows (amd64),
  enabling `hardening`, `openmp`, and `werror`.
- [`.github/workflows/muon.yml`](.github/workflows/muon.yml): builds and
  tests with muon (a C implementation of Meson) on AlmaLinux, Alpine Linux,
  Arch Linux, Fedora, openSUSE Leap, Ubuntu (amd64 and arm64), and macOS
  (arm64).
- [`.github/workflows/reuse.yml`](.github/workflows/reuse.yml): verifies
  REUSE license compliance.
- [`.github/workflows/sanitizer.yml`](.github/workflows/sanitizer.yml):
  builds and tests with AddressSanitizer, ThreadSanitizer, and
  UndefinedBehaviorSanitizer.
- [`.github/workflows/valgrind.yml`](.github/workflows/valgrind.yml): runs
  tests under Valgrind for memory error detection.
- [`.github/workflows/validate-cff.yml`](.github/workflows/validate-cff.yml):
  validates [`CITATION.cff`](CITATION.cff) against the CFF schema.
- [`.github/workflows/yamllint.yml`](.github/workflows/yamllint.yml): lints
  all YAML files with yamllint.

### Documentation Policy [2.v]

Changes are documented through commit messages and pull request descriptions
on GitHub.

## Documentation [3]

### Feature Documentation [3.i]

All features of `RVO2 Library` are documented in the Doxygen markup within
[`src/RVO.h`](src/RVO.h) and related headers, including a usage guide,
parameter overview, and example code. Three annotated example programs
([`examples/Blocks.cc`](examples/Blocks.cc),
[`examples/Circle.cc`](examples/Circle.cc),
[`examples/Roadmap.cc`](examples/Roadmap.cc)) demonstrate typical usage
patterns covering agents, obstacles, and step-wise simulation. HTML
documentation is generated by CMake (`-DBUILD_DOCUMENTATION=ON`).

### Public API Documentation [3.ii]

All public API elements are documented with Doxygen markup. HTML documentation
is generated from the source headers and installed with the library.

### License [3.iii]

Source code is licensed under the
[Apache License, Version 2.0](https://www.apache.org/licenses/LICENSE-2.0).
Documentation is licensed under the
[Creative Commons Attribution-ShareAlike 4.0 International (CC-BY-SA-4.0)](https://creativecommons.org/licenses/by-sa/4.0/)
Public License.

The project uses the [REUSE Specification](https://reuse.software/) for license
compliance. Every source file contains machine-readable SPDX license and
copyright headers, and license texts are provided in the [`LICENSES/`](LICENSES/)
directory. License compliance is verified by the `reuse` pre-commit hook and
by the [`.github/workflows/reuse.yml`](.github/workflows/reuse.yml) CI job.

### Copyright Statement [3.iv]

Copyright is held by the University of North Carolina at Chapel Hill. All
source files include the SPDX copyright notice:

```text
SPDX-FileCopyrightText: 2008 University of North Carolina at Chapel Hill
```

### Quality Declaration [3.v]

This document is the quality declaration for `RVO2 Library` and is linked from
the project README.

## Testing [4]

### Feature Testing [4.i]

Three system-level simulation scenarios form the test suite, run via `ctest`
(CMake), `bazel test` (Bazel), `meson test` (Meson), and `muon test` (muon):

- **Blocks**: 100 agents split into four groups navigating through a narrow
  passage formed by four obstacles.
- **Circle**: 250 agents initially distributed on a circle moving to their
  antipodal positions.
- **Roadmap**: The Blocks scenario augmented with roadmap-based global path
  planning.

These scenarios exercise all documented features of the library, including
agent management, obstacle processing, the k-D tree spatial index, and
step-wise simulation.

### Public API Testing [4.ii]

The three simulation scenarios collectively exercise all major public API
functions of `RVOSimulator`, `Vector2`, and `Line`. Dedicated unit tests for
individual API functions are not currently present.

### Coverage [4.iii]

Code coverage is measured in CI using `gcovr` via
[`.github/workflows/coverage.yml`](.github/workflows/coverage.yml), which
builds with `-Db_coverage=true` and produces an XML report. Coverage results
are uploaded to [DeepSource](https://deepsource.com/) on each push to `main`. The
three simulation scenarios provide broad functional coverage of the library,
but no minimum coverage threshold is currently enforced.

### Performance [4.iv]

No formal performance regression tests are in place. The simulation scenarios
implicitly exercise performance characteristics of the library (e.g., the
Circle scenario with 250 agents, and the Blocks scenario with obstacle
processing), but no automated performance benchmarks are run in CI.

### Linters and Static Analysis [4.v]

The following formatters and linters are enforced in CI:

- **actionlint**: GitHub Actions workflow validation via
  [`.github/workflows/actionlint.yml`](.github/workflows/actionlint.yml)
- **buildifier**: Bazel file formatting via [`.buildifier.json`](.buildifier.json)
  and [`.github/workflows/buildifier.yml`](.github/workflows/buildifier.yml)
- **check-jsonschema**: JSON schema validation of `compose.yaml` and
  `renovate.json` via
  [`.github/workflows/check-jsonschema.yml`](.github/workflows/check-jsonschema.yml)
- **clang-format**: code formatting enforced via [`.clang-format`](.clang-format)
  (Google style with `PointerAlignment: Right`)
- **codespell**: spell checking via
  [`.github/workflows/codespell.yml`](.github/workflows/codespell.yml)
- **cpplint**: Google C++ style enforcement via [`CPPLINT.cfg`](CPPLINT.cfg)
  and [`.github/workflows/cpplint.yml`](.github/workflows/cpplint.yml)
- **detect-secrets**: secret scanning against a maintained baseline via
  [`.secrets.baseline`](.secrets.baseline) and
  [`.github/workflows/detect-secrets.yml`](.github/workflows/detect-secrets.yml)
- **gersemi**: CMake file formatting via [`.gersemirc`](.gersemirc) and
  [`.github/workflows/gersemi.yml`](.github/workflows/gersemi.yml)
- **hadolint**: Dockerfile linting via [`.hadolint.yaml`](.hadolint.yaml) and
  [`.github/workflows/hadolint.yml`](.github/workflows/hadolint.yml)
- **validate-cff**: CFF schema validation via
  [`.github/workflows/validate-cff.yml`](.github/workflows/validate-cff.yml)
- **yamllint**: YAML file linting via
  [`.github/workflows/yamllint.yml`](.github/workflows/yamllint.yml) and
  [`.yamllint.yaml`](.yamllint.yaml)
- **pre-commit hooks**: `codespell` (spell checking), `yamllint`, `actionlint`
  (workflow validation), REUSE compliance, case-conflict, JSON, YAML, and
  merge-conflict detection, end-of-file and trailing-whitespace normalization
  via [`.pre-commit-config.yaml`](.pre-commit-config.yaml)

The following static analysis tools are enforced in CI:

- **clang-tidy**: static analysis via [`.clang-tidy`](.clang-tidy), enabling
  `bugprone-*`, `cert-*`, `clang-analyzer-*`, `cppcoreguidelines-*`,
  `google-*`, `performance-*`, `portability-*`, `readability-*`, and
  `openmp-*` checks, with `WarningsAsErrors: '*'`
- **CodeQL**: GitHub's semantic code analysis for C++ via
  [`.github/workflows/codeql.yml`](.github/workflows/codeql.yml)
- **cppcheck**: static analysis with all checks enabled via
  [`.cppcheck.xml`](.cppcheck.xml); results uploaded to GitHub Code Scanning
  as SARIF
- **include-what-you-use**: include hygiene checked via
  [`.iwyu_mappings.imp`](.iwyu_mappings.imp)
- **lizard**: cyclomatic complexity analysis via
  [`.github/workflows/lizard.yml`](.github/workflows/lizard.yml)

The following dynamic analysis tools are run against the test suite in CI:

- **AddressSanitizer, ThreadSanitizer, UndefinedBehaviorSanitizer**: enabled
  via [`.github/workflows/sanitizer.yml`](.github/workflows/sanitizer.yml)
  with `halt_on_error=1`
- **Valgrind**: memory error detection via
  [`.github/workflows/valgrind.yml`](.github/workflows/valgrind.yml) with
  `--leak-check=full` and `--errors-for-leak-kinds=definite,indirect`

## Dependencies [5]

### Direct Runtime ROS Dependencies [5.i]

None.

### Optional Direct Runtime ROS Dependencies [5.ii]

None.

### Direct Runtime non-ROS Dependencies [5.iii]

- **C++ Standard Library**: provided by the compiler toolchain (GCC, Clang, or
  MSVC). This is a de facto standard with no quality level concerns.
- **OpenMP** (optional): a widely-adopted, ISO-standardized API for shared-memory
  parallel computing, available in all major compiler toolchains. Enabling
  OpenMP parallelizes simulation steps across available processors.

## Platform Support [6]

`RVO2 Library` is built and tested continuously via GitHub Actions on the
following platforms:

| Platform       | Architecture | Build System              |
|----------------|--------------|---------------------------|
| AlmaLinux      | amd64        | CMake, Bazel, Meson, muon |
| Alpine Linux   | amd64        | CMake, Meson, muon        |
| Arch Linux     | amd64        | CMake, Bazel, Meson, muon |
| Fedora         | amd64        | CMake, Bazel, Meson, muon |
| openSUSE Leap  | amd64        | CMake, Bazel, Meson, muon |
| Ubuntu         | amd64, arm64 | CMake, Bazel, Meson, muon |
| macOS          | arm64        | CMake, Bazel, Meson, muon |
| Windows        | amd64        | CMake, Meson              |

## Security [7]

### Vulnerability Disclosure Policy [7.i]

The security policy is documented in
[`.github/SECURITY.md`](.github/SECURITY.md). Vulnerability reports should be
sent to [geom@cs.unc.edu](mailto:geom@cs.unc.edu). The current release is
supported with security updates when practical.

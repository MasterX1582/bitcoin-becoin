BeCoin Core integration/staging tree
=====================================

[![Build Status](https://travis-ci.org/becoin/becoin.svg?branch=master)](https://travis-ci.org/becoin/becoin)

https://www.becoin.org

What is BeCoin?
----------------

BeCoin is an experimental new digital currency that enables instant payments to
anyone, anywhere in the world. BeCoin uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. BeCoin Core is the name of open source
software which enables the use of this currency.

For more information, as well as an immediately useable, binary version of
the BeCoin Core software, see https://www.becoin.org/en/download.

License
-------

BeCoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see http://opensource.org/licenses/MIT.

Development process
-------------------

Developers work in their own trees, then submit pull requests when they think
their feature or bug fix is ready.

If it is a simple/trivial/non-controversial change, then one of the BeCoin
development team members simply pulls it.

If it is a *more complicated or potentially controversial* change, then the patch
submitter will be asked to start a discussion (if they haven't already) on the
[mailing list](https://lists.linuxfoundation.org/mailman/listinfo/becoin-dev)

The patch will be accepted if there is broad consensus that it is a good thing.
Developers should expect to rework and resubmit patches if the code doesn't
match the project's coding conventions (see [doc/developer-notes.md](doc/developer-notes.md)) or are
controversial.

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/becoin/becoin/tags) are created
regularly to indicate new official, stable release versions of BeCoin.

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write unit tests for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run (assuming they weren't disabled in configure) with: `make check`

There are also regression and integration tests of the RPC interface, written
in Python, that are run automatically on the build server.
These tests can be run with: `qa/pull-tester/rpc-tests.sh`

Every pull request is built for both Windows and Linux on a dedicated server,
and unit and sanity tests are automatically run. The binaries produced may be
used for manual QA testing — a link to them will appear in a comment on the
pull request posted by [BeCoinPullTester](https://github.com/BeCoinPullTester). See https://github.com/TheBlueMatt/test-scripts
for the build/test scripts.

### Manual Quality Assurance (QA) Testing

Large changes should have a test plan, and should be tested by somebody other
than the developer who wrote the code.
See https://github.com/becoin/QA/ for how to create a test plan.

Translations
------------

Changes to translations as well as new translations can be submitted to
[BeCoin Core's Transifex page](https://www.transifex.com/projects/p/becoin/).

Translations are periodically pulled from Transifex and merged into the git repository. See the
[translation process](doc/translation_process.md) for details on how this works.

**Important**: We do not accept translation changes as GitHub pull requests because the next
pull from Transifex would automatically overwrite them again.

Translators should also subscribe to the [mailing list](https://groups.google.com/forum/#!forum/becoin-translators).

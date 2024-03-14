# Mile.Windows.Internal Versioning

This document applies to all versions of Mile.Windows.Internal.

## Version Format

- Simple Version: `<Major>.<Minor> <Tag>`
  - Example: `9.0 Preview 1`
- Binary Version: `<Major>.<Minor>.<Build>.<Revision>`
  - Example: `9.0.2654.0`

## The rule for build and revision number

The build number is the number of days since June 26, 2016 because it's the day
I wrote an e-mail to Wen Jia Liu, the original author of System Informer
(originally Process Hacker) for getting the permission of using PHNT into my MIT
licensed open source projects and also get the permission on that day.

The revision number is the number of releases releases in the day corresponding
to the build number, and it counts from zero. So the first revision is 0 and 
the second revision is 1.

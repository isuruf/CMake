/*============================================================================
  CMake - Cross Platform Makefile Generator
  Copyright 2004-2009 Kitware, Inc.
  Copyright 2004 Alexander Neundorf (neundorf@kde.org)

  Distributed under the OSI-approved BSD License (the "License");
  see accompanying file Copyright.txt for details.

  This software is distributed WITHOUT ANY WARRANTY; without even the
  implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
  See the License for more information.
============================================================================*/
#ifndef cmExtraSublimeTextGenerator_h
#define cmExtraSublimeTextGenerator_h

#include "cmExternalMakefileProjectGenerator.h"

class cmLocalGenerator;
class cmMakefile;
class cmTarget;
class cmGeneratedFileStream;

/** \class cmExtraSublimeTextGenerator
 * \brief Write Sublime Text 2 project files for Makefile based projects
 */
class cmExtraSublimeTextGenerator : public cmExternalMakefileProjectGenerator
{
public:
  cmExtraSublimeTextGenerator();

  virtual const char* GetName() const
                        { return cmExtraSublimeTextGenerator::GetActualName();}
  static const char* GetActualName()
                        { return "SublimeText2";}
  static cmExternalMakefileProjectGenerator* New()
                                    { return new cmExtraSublimeTextGenerator; }
  /** Get the documentation entry for this generator.  */
  virtual void GetDocumentation(cmDocumentationEntry& entry,
                                const char* fullName) const;

  virtual void Generate();
private:

  void CreateProjectFile(const std::vector<cmLocalGenerator*>& lgs);

  void CreateNewProjectFile(const std::vector<cmLocalGenerator*>& lgs,
                                const std::string& filename);

  std::string BuildMakeCommand(const std::string& make, const char* makefile,
                               const char* target);
  void AppendTarget(cmGeneratedFileStream& fout,
                    const char* targetName,
                    cmTarget* target,
                    const char* make,
                    const cmMakefile* makefile,
                    const char* compiler,
                    std::set<std::string>& includeDirs,
                    std::set<std::string>& defines, bool firstTarget);

};

#endif

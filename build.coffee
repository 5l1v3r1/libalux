path = require 'path'

includes = [
  'include'
  'dependencies/ansa/include'
  'dependencies/ansa/dependencies/anlock/src'
]

sourceDirs = [
  'src/arch/api'
  'dependencies/ansa/src'
  'dependencies/ansa/dependencies/anlock/src'
]

module.exports = (Finder, Makefile, environment) ->
  arch = process.env['TARGET_ARCH']
  if not (arch in ['x64'])
    throw new Error 'unknown architecture: ' + arch
  
  finder = new Finder()
  for source in sourceDirs
    finder.search source
  finder.search 'src/arch/' + arch
  
  objdir = path.join environment.root, 'build/objects'
  makefile = new Makefile finder, includes, objdir
  targetDefine = "-D__LIBALUX_TARGET_#{arch.toUpperCase()}__"
  makefile.addFlags 'c', targetDefine
  makefile.addFlags 'cpp', targetDefine
  return makefile

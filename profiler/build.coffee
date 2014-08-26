path = require 'path'

includes = [
  '../libalux/include'
  '../libalux/dependencies/ansa/include'
  '../libalux/dependencies/ansa/dependencies/anlock/src'
]

sourceDirs = [
  'src'
]

module.exports = (Finder, Makefile, environment) ->
  arch = process.env['TARGET_ARCH']
  if not (arch in ['x64'])
    throw new Error 'unknown architecture: ' + arch
  
  finder = new Finder()
  for source in sourceDirs
    finder.search source
  
  objdir = path.join environment.root, 'build/objects'
  makefile = new Makefile finder, includes, objdir
  targetDefine = "-D__LIBALUX_TARGET_#{arch.toUpperCase()}__"
  makefile.addFlags 'c', targetDefine
  makefile.addFlags 'cpp', targetDefine
  return makefile

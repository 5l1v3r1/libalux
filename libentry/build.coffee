path = require 'path'

module.exports = (Finder, Makefile, environment) ->
  arch = process.env['TARGET_ARCH']
  if not (arch in ['x64'])
    throw new Error 'unknown architecture: ' + arch
  
  finder = new Finder()
  
  finder.search 'src/general'
  finder.search 'src/' + arch
  
  objdir = path.join environment.root, 'build/objects'
  makefile = new Makefile finder, [], objdir
  return makefile

# -*- coding: utf-8 -*-

import sys, os
import sphinx_rtd_theme

from sphinx.highlighting import lexers
from pygments.lexers.web import PhpLexer
from pygments.lexers.web import HtmlLexer

from datetime import datetime

lexers['php'] = PhpLexer(startinline=True)
lexers['php-annotations'] = PhpLexer(startinline=True)
lexers['html'] = HtmlLexer(startinline=True)

extensions = ['sphinx.ext.autodoc',
    'sphinx.ext.doctest',
    'sphinx.ext.todo',
    'sphinx.ext.coverage',
    'sphinx.ext.imgmath',
    'sphinx.ext.ifconfig']

source_suffix = '.rst'
master_doc = 'index'

project = 'Netgen Content Browser'
copyright = 'Netgen'
author = 'Netgen'

version = ''
release = ''

exclude_patterns = ['_build', '.venv']

html_theme = "sphinx_rtd_theme"

templates_path = ['_templates']

html_theme_options = {
    'collapse_navigation': True,
    'version_selector': True,
    'navigation_depth': 2,
}

html_context = {
    'copyright_url': 'https://netgen.io',
    'current_year': datetime.utcnow().year
}

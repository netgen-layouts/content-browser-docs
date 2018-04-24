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
    'sphinx.ext.ifconfig',
    'sensio.sphinx.configurationblock']

source_suffix = '.rst'
master_doc = 'index'

project = 'Netgen Content Browser'
copyright = 'Netgen'
author = 'Netgen'

version = ''
release = ''

exclude_patterns = ['_build']

html_theme = "sphinx_rtd_theme"
html_theme_path = [sphinx_rtd_theme.get_html_theme_path()]

templates_path = ['_templates']

html_theme_options = {
    'collapse_navigation': True,
    'display_version': True,
    'navigation_depth': 2,
}

html_context = {
    'copyright_url': 'https://www.netgenlabs.com',
    'current_year': datetime.utcnow().year
}
